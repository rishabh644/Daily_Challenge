def int_to_roman(num):
    #Define the mapping of integers to Roman numeral symbols

    val=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
    syb=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]

    roman_numeral=''

    i=0

    # Construct the Roman numeral

    while num>0:
        for _ in range(num//val[i]):
            roman_numeral+=syb[i]
            num-=val[i]
        i+=1
    return roman_numeral

#Example usage

print(int_to_roman(2566))
