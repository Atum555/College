<?php

function getDatabaseConnection(): PDO {
    $dbPath = __DIR__ . '/news.db';
    return new PDO("sqlite:{$dbPath}");
}
