<?php

function getAllNews(PDO &$db): array {
    $stmt = $db->prepare('  SELECT news.*, users.*, COUNT(comments.id) AS comments
                            FROM news 
                            JOIN users USING (username) 
                            LEFT JOIN comments ON comments.news_id = news.id
                            GROUP BY news.id, users.username
                            ORDER BY published DESC');

    $stmt->execute();
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getNewsArticle(PDO &$db, int|string $article_id): mixed {
    $stmt = $db->prepare('  SELECT *, COUNT(comments.id) AS comments
                            FROM news 
                            JOIN users USING (username) 
                            LEFT JOIN comments ON comments.news_id = news.id
                            WHERE news.id = :id');

    $stmt->bindParam(':id', $article_id);
    $stmt->execute();
    return $stmt->fetch(PDO::FETCH_ASSOC);
}
