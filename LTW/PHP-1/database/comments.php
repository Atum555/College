<?php

function getComments(PDO &$db, int|string $articleId): array {
    $stmt = $db->prepare('  SELECT * 
                            FROM comments 
                            JOIN users USING (username) 
                            WHERE comments.news_id = :id');

    $stmt->bindParam(':id', $articleId);
    $stmt->execute();
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}
