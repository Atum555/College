PRAGMA foreign_keys=ON;

DROP TABLE IF EXISTS User;
CREATE TABLE User (
    id INTEGER PRIMARY KEY,
    nickName TEXT NOT NULL,
    profilePicture TEXT,
    email TEXT NOT NULL, 
    passwordHash TEXT NOT NULL,
    phoneNumber TEXT,

    CONSTRAINT Unique_NickName UNIQUE(nickName),
    CONSTRAINT Unique_Email UNIQUE(email),
    CONSTRAINT Unique_PhoneNumber UNIQUE(phoneNumber),
    CONSTRAINT Valid_Email CHECK(email LIKE '%_@_%._%'),
    CONSTRAINT Valid_PhoneNumber CHECK (phoneNumber GLOB '9[1236][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')
);

DROP TABLE IF EXISTS Plan;
CREATE TABLE Plan (
    id INTEGER PRIMARY KEY,
    tier TEXT NOT NULL,
    cost INTEGER NOT NULL,
    duration INTEGER NOT NULL,

    CONSTRAINT Valid_PlanCost CHECK(cost >= 0),
    CONSTRAINT Valid_PlanDuration CHECK (duration >= 0)
);

-- Used INSERT to ensure that the DEFAULT on Listener.plan functions as expected, and consequently the ON DELETE SET DEFAULT as well.
INSERT INTO Plan VALUES (1, 'Free', 0, 0);

DROP TABLE IF EXISTS Listener;
CREATE TABLE Listener (
    id INTEGER PRIMARY KEY,
    plan INTEGER NOT NULL DEFAULT 1,
    subscriptionStart DATE NOT NULL DEFAULT CURRENT_DATE,
    totalListeningTime TIME NOT NULL DEFAULT '00:00:00',

    FOREIGN KEY (id) REFERENCES User(id) 
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (plan) REFERENCES Plan(id) 
    ON UPDATE CASCADE
    ON DELETE SET DEFAULT,

    CONSTRAINT Valid_SubscriptionStart CHECK (subscriptionStart <= CURRENT_DATE),
    -- Calculates and validates the real total listening time in seconds
    CONSTRAINT Valid_TotalListeningTime CHECK (strftime('%s', totalListeningTime) - strftime('%s', '00:00:00') >= 0)
);

DROP TABLE IF EXISTS Artist;
CREATE TABLE Artist (
    id INTEGER PRIMARY KEY,
    verifiedStatus BOOLEAN NOT NULL DEFAULT false,
    monthlyListeners INTEGER NOT NULL DEFAULT 0,

    FOREIGN KEY (id) REFERENCES User(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
    
    CONSTRAINT Valid_MonthlyListeners CHECK(monthlyListeners >= 0)
);

DROP TABLE IF EXISTS Follow;
CREATE TABLE Follow (
    artist INTEGER,
    listener INTEGER,

    PRIMARY KEY (artist, listener),

    FOREIGN KEY (artist) REFERENCES Artist(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (listener) REFERENCES Listener(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Interactable;
CREATE TABLE Interactable (
    id INTEGER PRIMARY KEY,
    date DATE NOT NULL DEFAULT CURRENT_DATE
);

DROP TABLE IF EXISTS Song;
CREATE TABLE Song (
    id INTEGER PRIMARY KEY,
    title TEXT NOT NULL,
    description TEXT,
    songFile TEXT NOT NULL,
    length TIME NOT NULL,
    lyrics TEXT,
    streamCount INTEGER NOT NULL DEFAULT 0,

    FOREIGN KEY (id) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    -- Calculates and validates the real song length in seconds
    CONSTRAINT Valid_SongLength CHECK (strftime('%s', length) - strftime('%s', '00:00:00') > 0),
    CONSTRAINT Valid_StreamCount CHECK (streamCount >= 0)
);

DROP TABLE IF EXISTS Genre;
CREATE TABLE Genre (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    description TEXT,

    CONSTRAINT Unique_GenreName UNIQUE(name)
);

DROP TABLE IF EXISTS SongGenre;
CREATE TABLE SongGenre (
    song INTEGER,
    genre INTEGER,

    PRIMARY KEY (song, genre),

    FOREIGN KEY (song) REFERENCES Song(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (genre) REFERENCES Genre(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Playlist;
CREATE TABLE Playlist (
    id INTEGER PRIMARY KEY,
    creator INTEGER NOT NULL,
    title TEXT NOT NULL,
    description TEXT,
    length TIME NOT NULL,

    FOREIGN KEY (id) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (creator) REFERENCES Listener(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    -- Calculates and validates the real playlist length in seconds
    CONSTRAINT Valid_PlaylistLength CHECK (strftime('%s', length) - strftime('%s', '00:00:00') > 0)
);

DROP TABLE IF EXISTS PlaylistSong;
CREATE TABLE PlaylistSong (
    playlist INTEGER NOT NULL,
    song INTEGER NOT NULL,

    PRIMARY KEY (playlist, song),

    FOREIGN KEY (playlist) REFERENCES Playlist(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (song) REFERENCES Song(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Release;
CREATE TABLE Release (
    id INTEGER PRIMARY KEY,
    publisher INTEGER NOT NULL,
    title TEXT NOT NULL,
    description TEXT,
    coverART TEXT,
    length TIME NOT NULL,


    FOREIGN KEY (id) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (publisher) REFERENCES Artist(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    CONSTRAINT Unique_CoverART UNIQUE(coverART),
    CONSTRAINT Valid_ReleaseLength CHECK (strftime('%s', length) - strftime('%s', '00:00:00') > 0)
);

DROP TABLE IF EXISTS Single;
CREATE TABLE Single (
    id INTEGER PRIMARY KEY,
    song INTEGER NOT NULL,
    isStandAlone BOOL NOT NULL,

    FOREIGN KEY (id) REFERENCES Release(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (song) REFERENCES Song(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Album;
CREATE TABLE Album (
    id INTEGER PRIMARY KEY,
    numberOfSongs INTEGER NOT NULL DEFAULT 0,

    FOREIGN KEY (id) REFERENCES Release(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    CONSTRAINT Valid_AlbumNumberOfSongs CHECK (numberOfSongs >= 0)
);

DROP TABLE IF EXISTS AlbumSong;
CREATE TABLE AlbumSong (
    album INTEGER,
    song INTEGER,

    PRIMARY KEY (album, song),

    FOREIGN KEY (album) REFERENCES Album(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (song) REFERENCES Song(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS FeaturedIn;
CREATE TABLE FeaturedIn (
    artist INTEGER,
    song INTEGER,

    PRIMARY KEY (artist, song),

    FOREIGN KEY (artist) REFERENCES Artist(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (song) REFERENCES Song(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Like;
CREATE TABLE Like (
    listener INTEGER,
    interactable INTEGER,

    PRIMARY KEY (listener, interactable),

    FOREIGN KEY (listener) REFERENCES Listener(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (interactable) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Save;
CREATE TABLE Save (
    listener INTEGER,
    interactable INTEGER,

    PRIMARY KEY (listener, interactable),

    FOREIGN KEY (listener) REFERENCES Listener(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (interactable) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

DROP TABLE IF EXISTS Comment;
CREATE TABLE Comment (
    id INTEGER PRIMARY KEY,
    commenter INTEGER NOT NULL,
    interactable INTEGER NOT NULL,
    text TEXT NOT NULL,

    FOREIGN KEY (id) REFERENCES Interactable(id),

    FOREIGN KEY (commenter) REFERENCES Listener(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,

    FOREIGN KEY (interactable) REFERENCES Interactable(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);
