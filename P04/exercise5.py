def deriv(f):
    def df(x, h=1e-3):
        return round((f(x+h) - f(x)) / h, 3)
    return df