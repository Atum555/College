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

function getNewsArticle(PDO &$db, string $article_id): mixed {
    $stmt = $db->prepare('  SELECT news.*, users.*, COUNT(comments.id) AS comments
                            FROM news 
                            JOIN users USING (username) 
                            LEFT JOIN comments ON comments.news_id = news.id
                            WHERE news.id = :id');

    $stmt->bindParam(':id', $article_id);
    $stmt->execute();
    return $stmt->fetch(PDO::FETCH_ASSOC);
}

function updateNewsArticle(PDO &$db, string $id, string $title, string $introduction, string $fulltext) {
    $stmt = $db->prepare('  UPDATE news 
                            SET title = :title, introduction = :introduction, fulltext = :fulltext
                            WHERE id = :id');

    $stmt->bindParam(':id', $id);
    $stmt->bindParam(':title', $title);
    $stmt->bindParam(':introduction', $introduction);
    $stmt->bindParam(':fulltext', $fulltext);

    $stmt->execute();
}
