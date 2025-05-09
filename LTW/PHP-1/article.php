<?php
include_once('database/connection.php');
include_once('database/news.php');
include_once('database/comments.php');
include_once('templates/common.php');
include_once('templates/news.php');

$db = getDatabaseConnection();
$article = getNewsArticle($db, $_GET['id']);
$comments = getComments($db, $_GET['id']);
?>

<!DOCTYPE html>
<html lang="en-US">

<?php output_head() ?>

<body>
    <?php output_header() ?>
    <?php output_nav() ?>
    <?php output_aside() ?>
    <main id="news">
        <?php output_article($article, $comments) ?>
    </main>
    <?php output_footer() ?>
</body>

</html>
