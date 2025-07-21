const express = require("express");
const router = express.Router();

const mongoose = require("mongoose");
const User = require("./models/User");
const Book = require("./models/Book");
const ErrorResponse = require("./utils/errorResponse");
const { protect } = require("./utils/authMiddleware");

// Helper function to check admin role
const checkAdmin = (req, res) => {
	if (req.user.role !== "admin") {
		return res.status(200).json({
			success: false,
			data: { message: "Not an admin" },
		});
	}
	return null;
};

/*
GET /books/all
*/
router.get("/books/all", protect, async (req, res, next) => {
	try {
		const books = await Book.find({}).sort({ createdAt: 1 });
		res.status(200).json({ success: true, data: books });
	} catch (err) {
		next(err);
	}
});

/*
GET /books/:id
*/
router.get("/books/:id", protect, async (req, res, next) => {
	try {
		const book = await Book.findById(req.params.id);
		if (!book) {
			return next(new ErrorResponse("Book not found", 404));
		}
		res.status(200).json({ success: true, data: book });
	} catch (err) {
		next(err);
	}
});

/*
POST /books/add [ONLY FOR ADMIN]
*/
router.post("/books/add", protect, async (req, res, next) => {
	const adminCheck = checkAdmin(req, res);
	if (adminCheck) return adminCheck;

	try {
		const { title, description, noInStock } = req.body;
		const book = await Book.create({ title, description, noInStock });
		res.status(200).json({ success: true, data: book });
	} catch (err) {
		next(err);
	}
});

/*
PUT /books/updatestock/:id [ONLY FOR ADMIN]
*/
router.put("/books/updatestock/:id", protect, async (req, res, next) => {
	const adminCheck = checkAdmin(req, res);
	if (adminCheck) return adminCheck;

	try {
		const { stock } = req.body;
		const book = await Book.findByIdAndUpdate(
			req.params.id,
			{ noInStock: stock },
			{ new: true }
		);
		if (!book) {
			return next(new ErrorResponse("Book not found", 404));
		}
		res.status(200).json({ success: true, data: book });
	} catch (err) {
		next(err);
	}
});

/*
DELETE /books/delete/:id [ONLY FOR ADMIN]
*/
router.delete("/books/delete/:id", protect, async (req, res, next) => {
	const adminCheck = checkAdmin(req, res);
	if (adminCheck) return adminCheck;

	try {
		const book = await Book.findByIdAndDelete(req.params.id);
		if (!book) {
			return next(new ErrorResponse("Book not found", 404));
		}
		res.status(200).json({
			success: true,
			data: { message: "Book deleted successfully" },
		});
	} catch (err) {
		next(err);
	}
});

/*
POST /books/borrow/:id
*/
router.post("/books/borrow/:id", protect, async (req, res, next) => {
	try {
		const user = await User.findById(req.user.id);
		if (user.borrowedBooks.includes(req.params.id)) {
			return res.status(200).json({
				success: false,
				data: { message: "Already Borrowed" },
			});
		}
		user.borrowedBooks.push(req.params.id);
		await user.save();

		res.status(200).json({
			success: true,
			data: { message: "Book borrowed successfully" },
		});
	} catch (err) {
		next(err);
	}
});

/*
GET /user/profile
*/
router.get("/user/profile", protect, async (req, res, next) => {
	try {
		const user = await User.findById(req.user.id).populate("borrowedBooks");
		res.status(200).json({
			success: true,
			data: user,
		});
	} catch (err) {
		next(err);
	}
});

/*
POST /books/like/:id
*/
router.post("/books/like/:id", protect, async (req, res, next) => {
	try {
		const book = await Book.findById(req.params.id);
		if (book.likes.includes(req.user.id)) {
			return res.status(200).json({
				success: false,
				data: { message: "Already liked" },
			});
		}
		book.likes.push(req.user.id);
		await book.save();

		res.status(200).json({
			success: true,
			data: { message: "Successfully liked book" },
		});
	} catch (err) {
		next(err);
	}
});

/*
POST /books/unlike/:id
*/
router.post("/books/unlike/:id", protect, async (req, res, next) => {
	try {
		const book = await Book.findById(req.params.id);
		if (!book.likes.includes(req.user.id)) {
			return res.status(200).json({
				success: false,
				data: { message: "Not liked" },
			});
		}
		book.likes = book.likes.filter((like) => like.toString() !== req.user.id);
		await book.save();

		res.status(200).json({
			success: true,
			data: { message: "Successfully unliked book" },
		});
	} catch (err) {
		next(err);
	}
});

/*
POST /books/review/:id
*/
router.post("/books/review/:id", protect, async (req, res, next) => {
	try {
		const { review } = req.body;
		const book = await Book.findById(req.params.id);
		if (!book) {
			return next(new ErrorResponse("Book not found", 404));
		}
		book.reviews.push({ user: req.user.id, review });
		await book.save();

		res.status(200).json({
			success: true,
			data: { message: "Successfully added review for book" },
		});
	} catch (err) {
		next(err);
	}
});

module.exports = router;
