<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sum 2 Numbers</title>
</head>

<body>
    <?php
    if (
        $_GET['num1'] === null or $_GET['num2'] === null or
        $_GET['num1'] === '' or $_GET['num2'] === ''
    ) include('form.html');
    else {
    ?>
        <p>
            <?= $_GET['num1'] . ' + ' . $_GET['num2'] . ' = ' . ($_GET['num1'] + $_GET['num2']); ?>
        </p>

        <p><a href="/sum2.php">Do another sum</a></p>

    <?php
    }
    ?>
</body>

</html>
