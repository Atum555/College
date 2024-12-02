import random
import string
import numpy as np

# Read Human Names List
human_names = []
with open("names.txt", 'r') as f:
    for name in f.readlines():
        human_names.append(name.strip())
        
song_titles = []
with open("song_titles.txt", 'r') as f:
    for title in f.readlines():
        song_titles.append(title.strip())

def generate_random_string(length):
    characters = string.ascii_uppercase + string.digits
    return ''.join(random.choice(characters) for _ in range(length))

def generate_nickNameAndEmail():    
    domains = [
        "gmail.com", "yahoo.com", "outlook.com", "hotmail.com", "icloud.com",
        "aol.com", "mail.com", "protonmail.com", "zoho.com", "yandex.com",
        "gmx.com", "fastmail.com", "hushmail.com", "live.com", "me.com",
        "rocketmail.com", "inbox.com", "msn.com", "rediffmail.com", "verizon.net",
        "comcast.net", "att.net", "charter.net", "cox.net", "bellsouth.net",
        "earthlink.net"
    ]
    
    nickNamePatters = [
        "{first}{last}",
        "{number}{first}{last}",
        "{first}{number}{last}",
        "{first}{last}{number}",
        
        "{first}.{last}",
        "{number}{first}.{last}",
        "{first}.{number}{last}",
        "{first}.{last}{number}",

        "{first}_{last}",
        "{number}{first}_{last}",
        "{first}_{number}{last}",
        "{first}_{last}{number}",

        "{first}{last[0]}",
        "{number}{first}{last[0]}",
        "{first}{number}{last[0]}",
        "{first}{last[0]}{number}",

        "{first[0]}{last}",
        "{number}{first[0]}{last}",
        "{first[0]}{number}{last}",
        "{first[0]}{last}"
    ]
    
    emailPatterns = [
        "{first}{last}@{domain}",
        "{number}{first}{last}@{domain}",
        "{first}{number}{last}@{domain}",
        "{first}{last}{number}@{domain}",
        
        "{first}.{last}@{domain}",
        "{number}{first}.{last}@{domain}",
        "{first}.{number}{last}@{domain}",
        "{first}.{last}{number}@{domain}",

        "{first}_{last}@{domain}",
        "{number}{first}_{last}@{domain}",
        "{first}_{number}{last}@{domain}",
        "{first}_{last}{number}@{domain}",

        "{first}{last[0]}@{domain}",
        "{number}{first}{last[0]}@{domain}",
        "{first}{number}{last[0]}@{domain}",
        "{first}{last[0]}{number}@{domain}",

        "{first[0]}{last}@{domain}",
        "{number}{first[0]}{last}@{domain}",
        "{first[0]}{number}{last}@{domain}",
        "{first[0]}{last}@{domain}"
    ]
    
    first = random.choice(human_names)
    last = random.choice(human_names)
    number = str(int(random.random() * 1000))
    domain = random.choice(domains)
    nickNamePattern = random.choice(nickNamePatters)
    emailPattern = random.choice(emailPatterns)
    
    return (
        nickNamePattern.format(first=first, last=last, number=number), 
        emailPattern.format(first=first, last=last, number=number, domain=domain)
    )

def generate_date():
    year = random.randrange(1980, 2024)
    month = random.randrange(1, 13)
    day = random.randrange(1, 29)

    return f"{year}-{month:02d}-{day:02d}"

def generate_totalListeningTime():
    hour = min(int(np.random.exponential(30)), 99)
    minutes = int(random.randrange(1, 60))
    sec = int(random.randrange(1, 60))
    
    return f"{hour:02d}:{minutes:02d}:{sec:02d}"

def generate_songLength():
    minutes = max(min(int(np.random.exponential(3)), 15), 1)
    sec = int(random.randrange(1, 60))
    return f"00:{minutes:02d}:{sec:02d}"

def sum_time(a:str, b:str):
    (ah, am, aseg) = tuple(map(int, a.split(':')))
    (bh, bm, bseg) = tuple(map(int, b.split(':')))
    
    h = ah + bh
    m = am + bm
    s = aseg + bseg
    m = m + s // 60
    h = h + m // 60
    s = s % 60
    m = m % 60
    
    return f"{h:02d}:{m:02d}:{s:02d}"
    
#### COUNTS
userCount = 5000
totalNumberOfReleases = 1000
totalNumberOfSongs = totalNumberOfReleases * 10
totalNumberOfPlaylists = int(userCount * 1.5)
totalNumberOfLikes = userCount * 100
totalNumberOfSaves = userCount * 100
totalNumberOfComments = userCount * 3


###### PLANS
print("Generating Plans")
plans = [
    (1, "Free", 0, 0),
    (2, "Starter Groove", 2, 1),
    (3, "Student", 3, 2),
    (4, "Prime Sound", 4, 1),
    (5, "Infinite Tracks", 40, 12)
]

######  USER

# Create Profile Picture
print("Generating Profile Pictures")
profilePictureLength = 100
profilePictures = set()
while len(profilePictures) != userCount:
    profilePictures.add(generate_random_string(profilePictureLength) if random.random() < 0.95 else "NULL")
profilePictures = list(profilePictures)

# Create NickNames and Emails
print("Generating NickNames and Emails")
userNickNames = []
userEmails = []
while(len(userNickNames) != userCount):
    (nickName, email) = generate_nickNameAndEmail()
    if nickName not in userNickNames and email not in userEmails:
        userNickNames.append(nickName)
        userEmails.append(email) 

# Create Password Hashes
print("Generating Password Hashes")
passwordHashLength = 100
passwordHashes = set()
while len(passwordHashes) != userCount:
    passwordHashes.add(generate_random_string(passwordHashLength))
passwordHashes = list(passwordHashes)

# Create Phone Numbers
print("Generating Phone Numbers")
phoneNumbers = set()
while len(phoneNumbers) != userCount:
    phoneNumbers.add(
        "9" + random.choice(["1", "2", "3", "6"]) +
        ''.join(list((str(int(random.random() * 10)) for _ in range(7))))
    )
phoneNumbers = list(phoneNumbers)
for i in range(len(phoneNumbers)):
    if random.random() >= 0.95:
        phoneNumbers[i] = "NULL"
        
# Create Users
print("Generating Users", end=" ")
users = [
    (id, userNickNames[id-1], profilePictures[id-1], userEmails[id-1], passwordHashes[id-1], phoneNumbers[id-1])
    for id in range(1, userCount+1)
]
print(f"\033[92m{len(users)}\033[00m")

###### Listener
print("Generating Listeners", end=" ")
listeners = [
    (user[0], random.choice(plans)[0], generate_date(), generate_totalListeningTime())
    for user in users
]
print(f"\033[92m{len(listeners)}\033[00m")

###### Artist
print("Generating Artists", end=" ")
artists = [
    (user[0], str(random.random() < 0.2), random.randrange(userCount // 1000, userCount))
    for user in users
    if random.random() < 0.05 or user[0] < 10
]
print(f"\033[92m{len(artists)}\033[00m")

###### Follow
print("Generating Follows", end=" ")
follows = [
    (artist[0], listener[0])
    for artist in artists
    for listener in listeners
    if random.random() < 0.4
]
print(f"\033[92m{len(follows)}\033[00m")

###### Genre
print("Generating Genres", end=" ")
genres = [
    (1, "Pop", "A genre of popular music with catchy melodies and broad appeal."),
    (2, "Rock", "Characterized by electric guitars, strong rhythms, and powerful vocals."),
    (3, "Hip-Hop", "Focused on rhythm, beats, and lyrical expression often with rap."),
    (4, "Jazz", "Known for improvisation, swing, and complex harmonies."),
    (5, "Classical", "Art music rooted in Western traditions, often featuring orchestras."),
    (6, "Country", "A genre with roots in folk, focusing on storytelling and acoustic instruments."),
    (7, "Electronic", "Music produced using electronic instruments and technology."),
    (8, "Reggae", "Originating in Jamaica, characterized by offbeat rhythms and a focus on bass."),
    (9, "Blues", "Features emotional vocals and guitar, often expressing sorrow or hardship."),
    (10, "R&B", "Rhythm and Blues, combining soul, funk, and pop influences."),
    (11, "Metal", "A louder, more aggressive form of rock music with heavy guitar riffs."),
    (12, "Folk", "Traditional music focusing on acoustic instruments and cultural storytelling."),
    (13, "Soul", "A blend of gospel, R&B, and jazz with an emphasis on vocal emotion."),
    (14, "Latin", "Music originating from Latin America, featuring rich rhythms and melodies."),
    (15, "K-pop", "Korean pop music known for its polished production and vibrant choreography."),
    (16, "Reggaeton", "A mix of reggae, hip-hop, and Latin rhythms, often danceable."),
    (17, "Indie", "Independent music that often defies mainstream trends."),
    (18, "Punk", "Raw and rebellious, often characterized by short, fast-paced songs."),
    (19, "EDM", "Electronic Dance Music, designed for nightclubs and festivals."),
    (20, "World", "Music that reflects cultural traditions from around the globe.")
]
print(f"\033[92m{len(genres)}\033[00m")

###### Interactable
interactableS = []

###### Song
print("Generating Songs", end=" ")
songFileLength = 100
songs = []
for i in range(1, totalNumberOfSongs+1):
    interactableS.append((i, generate_date()))
    songs.append((
        i,
        random.choice(song_titles),
        random.choice(song_titles),
        generate_random_string(songFileLength),
        generate_songLength(),
        " ".join(random.choice(song_titles) for _ in range(20)),
        min(int(np.random.exponential(40000)), 1_000_000)
    ))
print(f"\033[92m{len(songs)}\033[00m")
    
###### SongGenre
print("Generating SongGenres", end=" ")
songGenres = [
    (song[0], genre[0])
    for song in songs
    for genre in (random.sample(genres, max(int(np.random.exponential(1)), 1)))
]
print(f"\033[92m{len(songGenres)}\033[00m")

###### Playlist
print("Generating Playlists", end=" ")
lastInteractableId = interactableS[len(interactableS) - 1][0] + 1
playlists = []
for id in range(lastInteractableId, lastInteractableId + totalNumberOfPlaylists):
    interactableS.append((id, generate_date()))
    playlists.append((
        id, 
        listeners[random.randrange(0, len(listeners))][0],
        random.choice(song_titles),
        random.choice(song_titles),
        '00:00:00'
    ))
print(f"\033[92m{len(playlists)}\033[00m")
    
###### PlaylistSong
print("Generating PlaylistSongs", end=" ")
playlistSongs = list(set(
    (playlist[0], (song := random.choice(songs))[0], song[4])
    for playlist in playlists
    for _ in range(max(min(int(np.random.exponential(80)), 200), 5))
))
print(f"\033[92m{len(playlistSongs)}\033[00m")

print("Calculating PlaylistLengths")
for i, playlist in enumerate(playlists):
    for playlistSong in playlistSongs:
        if playlistSong[0] == playlist[0]:
            playlist = list(playlist)
            playlist[4] = sum_time(playlist[4], playlistSong[2])
            playlists[i] = playlist
                    
###### Release
print("Generating Releases", end=" ")
lastInteractableId = interactableS[len(interactableS) - 1][0] + 1
releases = []
for id in range(lastInteractableId, lastInteractableId + totalNumberOfReleases):
    interactableS.append((id, generate_date()))
    releases.append((
        id,
        random.choice(artists)[0],
        random.choice(song_titles),
        random.choice(song_titles) if random.random() < 0.9 else "NULL",
        generate_random_string(100),
        "00:00:00"
    ))
print(f"\033[92m{len(releases)}\033[00m")

###### Single
print("Generating Singles", end=" ")
singles = [
    (release[0], (song := random.choice(songs))[0], True, song[4])
    for release in releases
    if random.random() < 0.2
]
print(f"\033[92m{len(singles)}\033[00m")

###### Album
print("Generating Albums", end=" ")
albums = [
    (release[0], 0)
    for release in releases
    if release[0] not in map(lambda x: x[0], singles)
]
print(f"\033[92m{len(albums)}\033[00m")

###### AlbumSong
print("Generating AlbumSongs", end=" ")
albumSongs = [
    (album[0], song[0], song[4])
    for album in albums
    for song in random.sample(songs, max(min(int(np.random.exponential(15)), 50), 3))
    if song[0] not in map(lambda single: single[1], singles)
]
print(f"\033[92m{len(albumSongs)}\033[00m")

###### Singles StandAlone
print("Calculating Singles Stand Alone")
for i, single in enumerate(singles):
    for albumSong in albumSongs:
        if albumSong[1] == single[1]:
            single = list(single)
            single[2] = False
            singles[i] = tuple(single)

###### Releases Length
print("Calculating Releases Length")
for single in singles:
    for i, release in enumerate(releases):
        if single[0] == release[0]:
            release = list(release)
            release[5] = sum_time(release[5], single[3])
            releases[i] = tuple(release)

for album in albums:
    for i, release in enumerate(releases):
        if album[0] == release[0]:
            release = list(release)
            for albumSong in albumSongs:
                if albumSong[0] == album[0]:
                    release[5] = sum_time(release[5], albumSong[2])
            releases[i] = tuple(release)

###### Comment
print("Generating Comments", end=" ")
lastInteractableId = interactableS[len(interactableS) - 1][0] + 1
comments = []
while len(comments) != totalNumberOfComments:
    interactableS.append((lastInteractableId, generate_date()))
    comments.append((   
        lastInteractableId,
        random.choice(listeners)[0],
        0,
        " ".join(random.choice(song_titles) for _ in range(random.randrange(1, 20)))
    ))
    lastInteractableId += 1
print(f"\033[92m{len(comments)}\033[00m")

for i, comment in enumerate(comments):
    comment = list(comment)
    comment[2] = random.choice(interactableS)[0]
    comments[i] = tuple(comment)
    
##### Like
print("Generating Likes", end=" ")
likes = []
while len(likes) != totalNumberOfLikes:
    likes.append((random.choice(listeners)[0], random.choice(interactableS)[0]))
likes = list(set(likes))
print(f"\033[92m{len(likes)}\033[00m")

##### Save
print("Generating Saves", end=" ")
saves = []
while len(saves) != totalNumberOfLikes:
    saves.append((random.choice(listeners)[0], random.choice(interactableS)[0]))
saves = list(set(saves))
print(f"\033[92m{len(saves)}\033[00m")


# Create SQL
print("Writing")
with open("sql_populate.sql", 'w') as f:
    f.write("PRAGMA foreign_keys=ON;\n\nBEGIN TRANSACTION;\n\n")
    
    # Write Plans
    f.write(f"INSERT INTO Plan(tier, cost, duration) VALUES")
    for i in range(len(plans)):
        plan = plans[i]
        if plan[0] == 1: continue
        f.write(f"\n('{plan[1]}', {plan[2]}, {plan[3]}){"," if i != len(plans) - 1 else ";\n\n"}")
        
    # Write Users
    f.write(f"INSERT INTO User VALUES")
    for i in range(len(users)):
        user = users[i]
        f.write(f"\n({user[0]}, '{user[1]}', '{user[2]}', '{user[3]}', '{user[4]}', '{user[5]}'){"," if i != len(users) - 1 else ";\n\n"}".replace("'NULL'", "NULL"))

    # Write Listeners
    f.write("INSERT INTO Listener VALUES")
    for i in range(len(listeners)):
        listener = listeners[i]
        f.write(f"\n({listener[0]}, {listener[1]}, '{listener[2]}', '{listener[3]}'){"," if i != len(listeners) - 1 else ";\n\n"}")

    # Write Artists
    f.write("INSERT INTO Artist VALUES")
    for i in range(len(artists)):
        artist = artists[i]
        f.write(f"\n({artist[0]}, {artist[1]}, {artist[2]}){"," if i != len(artists) - 1 else ";\n\n"}")

    # Write Follows
    f.write("INSERT INTO Follow VALUES")
    for i in range(len(follows)):
        follow = follows[i]
        f.write(f"\n({follow[0]}, {follow[1]}){"," if i != len(follows) - 1 else ";\n\n"}")        
    
    # Write Genres
    f.write("INSERT INTO Genre VALUES")
    for i in range(len(genres)):
        genre = genres[i]
        f.write(f"\n({genre[0]}, '{genre[1]}', '{genre[2]}'){"," if i != len(genres) - 1 else ";\n\n"}")        

    # Write InteractableS
    f.write("INSERT INTO Interactable VALUES")
    for i in range(len(interactableS)):
        interactable = interactableS[i]
        f.write(f"\n({interactable[0]}, '{interactable[1]}'){"," if i != len(interactableS) - 1 else ";\n\n"}")        

    # Write Songs
    f.write("INSERT INTO Song VALUES")
    for i in range(len(songs)):
        song = songs[i]
        f.write(f"\n({song[0]}, '{song[1]}', '{song[2]}', '{song[3]}', '{song[4]}', '{song[5]}', {song[6]}){"," if i != len(songs) - 1 else ";\n\n"}")        

    # Write SongGenres
    f.write("INSERT INTO SongGenre VALUES")
    for i in range(len(songGenres)):
        songGenre = songGenres[i]
        f.write(f"\n({songGenre[0]}, {songGenre[1]}){"," if i != len(songGenres) - 1 else ";\n\n"}")        

    # Write Playlists
    f.write("INSERT INTO Playlist VALUES")
    for i in range(len(playlists)):
        playlist = playlists[i]
        f.write(f"\n({playlist[0]}, {playlist[1]}, '{playlist[2]}', '{playlist[3]}', '{playlist[4]}'){"," if i != len(playlists) - 1 else ";\n\n"}")        

    # Write PlaylistSongs
    f.write("INSERT INTO PlaylistSong VALUES")
    for i in range(len(playlistSongs)):
        playlistSong = playlistSongs[i]
        f.write(f"\n({playlistSong[0]}, {playlistSong[1]}){"," if i != len(playlistSongs) - 1 else ";\n\n"}")        
    
    # Write Releases
    f.write("INSERT INTO Release VALUES")
    for i in range(len(releases)):
        release = releases[i]
        f.write(f"\n({release[0]}, {release[1]}, '{release[2]}', '{release[3]}', '{release[4]}', '{release[5]}'){"," if i != len(releases) - 1 else ";\n\n"}".replace("'NULL'", "NULL"))        

    # Write Singles
    f.write("INSERT INTO Single VALUES")
    for i in range(len(singles)):
        single = singles[i]
        f.write(f"\n({single[0]}, {single[1]}, {str(single[2]).lower()}){"," if i != len(singles) - 1 else ";\n\n"}")        

    # Write Albums
    f.write("INSERT INTO Album VALUES")
    for i in range(len(albums)):
        album = albums[i]
        f.write(f"\n({album[0]}, {album[1]}){"," if i != len(albums) - 1 else ";\n\n"}")        

    # Write AlbumSongs
    f.write("INSERT INTO AlbumSong VALUES")
    for i in range(len(albumSongs)):
        albumSong = albumSongs[i]
        f.write(f"\n({albumSong[0]}, {albumSong[1]}){"," if i != len(albumSongs) - 1 else ";\n\n"}")        

    # Write Comments
    f.write("INSERT INTO Comment VALUES")
    for i in range(len(comments)):
        comment = comments[i]
        f.write(f"\n({comment[0]}, {comment[1]}, {comment[2]}, '{comment[3]}'){"," if i != len(comments) - 1 else ";\n\n"}")        

    # Write Likes
    f.write("INSERT INTO Like VALUES")
    for i in range(len(likes)):
        like = likes[i]
        f.write(f"\n({like[0]}, {like[1]}){"," if i != len(likes) - 1 else ";\n\n"}")        

    # Write Saves
    f.write("INSERT INTO Save VALUES")
    for i in range(len(saves)):
        save = saves[i]
        f.write(f"\n({save[0]}, {save[1]}){"," if i != len(saves) - 1 else ";\n\n"}")        
    
    
    f.write("COMMIT;\n")
