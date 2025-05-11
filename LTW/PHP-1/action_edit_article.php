<?php
include_once('database/connection.php');
include_once('database/news.php');
include_once('database/comments.php');
include_once('templates/common.php');
include_once('templates/news.php');

$db = getDatabaseConnection();
updateNewsArticle($db, $_POST['id'], $_POST['title'], $_POST['introduction'], $_POST['fulltext']);
header('Location: /article.php?id=' . $_POST['id']);
exit();
