<?php

function userExists(PDO $db, string $userName, string $password): bool {
    $query = 'SELECT * FROM users WHERE username = :username AND password = :password';
    $stmt = $db->prepare($query);
    $stmt->bindParam(':username', $userName);
    $stmt->bindParam(':password', $password);
    $stmt->execute([$userName, $password]);
    return $stmt->fetch() !== false;
}

function userNameExists(PDO $db, string $userName): bool {
    $query = 'SELECT * FROM users WHERE username = :username';
    $stmt = $db->prepare($query);
    $stmt->bindParam(':username', $userName);
    $stmt->execute();
    return $stmt->fetch() !== false;
}

function isUserLoggedIn(PDO $db): bool {
    return isset($_SESSION['username']) && !empty($_SESSION['username']) && userNameExists($db, $_SESSION['username']);
}

function createUser(PDO $db, string $userName, string $password): bool {
    $query = 'INSERT INTO users (username, password) VALUES (:username, :password)';
    $stmt = $db->prepare($query);
    $stmt->bindParam(':username', $userName);
    $stmt->bindParam(':password', $password);
    return $stmt->execute();
}
