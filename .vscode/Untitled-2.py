

def decor():
    def inner_func():
        print("dadsa")

@decor
def function():
    print("3131")


function()