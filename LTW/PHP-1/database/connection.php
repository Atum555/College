<?php

function getDatabaseConnection(): PDO {
    $dbPath = __DIR__ . '/database.db';
    return new PDO("sqlite:{$dbPath}");
}
