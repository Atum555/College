def tfidf(documents:list):
    from math import log

    words = set()
    for doc in documents: words |= {x.lower() for x in doc.split(" ")}

    tf = {}
    for word in words:
        temp = []
        for doc in documents: temp.append(doc.lower().split().count(word))
        tf[word] = temp
    
    for word in tf:
        idf = log(len(documents) / (len(documents) - tf[word].count(0)))
        tf[word] = list(map(lambda x: round(x * idf, 3), tf[word]))
    return tf