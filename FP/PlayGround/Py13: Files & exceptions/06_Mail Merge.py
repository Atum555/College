def mail_merge(names:str, mail_template:str):
    with open(mail_template, "r") as f:
        mail_template = f.read()
    with open(names, "r") as f:
        r = list(map(lambda x: (x.strip()).join(mail_template.split("<name>")), f))
    return r