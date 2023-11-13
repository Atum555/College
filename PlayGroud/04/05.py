def get_positions(sentence:str, word_list:list):
    sentence = sentence.split(" ")
    r = []
    for x in sentence:
        try: r.append(str(word_list.index(x))) 
        except ValueError: return ""
    return " ".join(r)