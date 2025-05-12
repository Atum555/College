<?php
session_start();
include_once('database/connection.php');
include_once('database/users.php');
include_once('database/news.php');
include_once('database/comments.php');
include_once('templates/common.php');
include_once('templates/news.php');

$db = getDatabaseConnection();
?>

<!DOCTYPE html>
<html lang="en-US">

<?php output_head() ?>

<body>
    <?php output_header($db) ?>
    <?php output_nav() ?>
    <?php output_aside() ?>
    <main id="login-register">
        <h1>Register</h1>
        <form>
            <label>Username<input type="text" name="username" /></label>
            <label>Password<input type="password" name="password" /></label>
            <button formaction="/action_register.php" formmethod="post">Register</button>
        </form>
    </main>
    <?php output_footer() ?>
</body>

</html>
