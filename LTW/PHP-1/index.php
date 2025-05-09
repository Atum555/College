<?php
$db = new PDO('sqlite:news.db');
$stmt = $db->prepare('  SELECT news.*, users.*, COUNT(comments.id) AS comments
                        FROM news 
                        JOIN users USING (username) 
                        LEFT JOIN comments ON comments.news_id = news.id
                        GROUP BY news.id, users.username
                        ORDER BY published DESC');
$stmt->execute();
$articles = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="en-US">

<head>
    <title>Super Legit News</title>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="/styles/style.css" />
    <link rel="stylesheet" href="/styles/layout.css" />
    <link rel="stylesheet" href="/styles/comments.css" />
    <link rel="stylesheet" href="/styles/responsive.css" />
</head>

<body>
    <header>
        <h1><a href="/">Super Legit News</a></h1>
        <h2><a href="/">Where fake news are born!</a></h2>
        <div id="signup">
            <a href="/">Register</a>
            <a href="/">Login</a>
        </div>
    </header>
    <nav id="menu">
        <!-- just for the hamburguer menu in responsive layout -->
        <input type="checkbox" id="hamburger" />
        <label class="hamburger" for="hamburger"></label>

        <ul>
            <li><a href="/">Local</a></li>
            <li><a href="/">World</a></li>
            <li><a href="/">Politics</a></li>
            <li><a href="/">Sports</a></li>
            <li><a href="/">Science</a></li>
            <li><a href="/">Weather</a></li>
        </ul>
    </nav>
    <aside id="related">
        <article>
            <h1><a href="#">Duis arcu purus</a></h1>
            <p>
                Etiam mattis convallis orci eu malesuada. Donec odio ex, facilisis ac blandit vel, placerat ut
                lorem. Ut id sodales purus. Sed ut ex sit amet nisi ultricies malesuada. Phasellus magna diam,
                molestie nec quam a, suscipit finibus dui. Phasellus a.
            </p>
        </article>
        <article>
            <h1><a href="#">Sed efficitur interdum</a></h1>
            <p>
                Integer massa enim, porttitor vitae iaculis id, consequat a tellus. Aliquam sed nibh fringilla,
                pulvinar neque eu, varius erat. Nam id ornare nunc. Pellentesque varius ipsum vitae lacus ultricies,
                a dapibus turpis tristique. Sed vehicula tincidunt justo, vitae varius arcu.
            </p>
        </article>
        <article>
            <h1><a href="#">Vestibulum congue blandit</a></h1>
            <p>
                Proin lectus felis, fringilla nec magna ut, vestibulum volutpat elit. Suspendisse in quam sed tellus
                fringilla luctus quis non sem. Aenean varius molestie justo, nec tincidunt massa congue vel. Sed
                tincidunt interdum laoreet. Vivamus vel odio bibendum, tempus metus vel.
            </p>
        </article>
    </aside>
    <section id="news">
        <?php foreach ($articles as $article) { ?>
            <article>
                <header>
                    <h1><a href="/article.php?id=<?= $article['id'] ?>"><?= $article['title'] ?></a></h1>
                </header>
                <img src="https://picsum.photos/600/300?<?= $article['id'] ?>" alt="" />
                <p>
                    <?= $article['introduction'] ?>
                </p>
                <?php
                foreach (explode("\n", $article['fulltext']) as $paragraph) {
                    if ($paragraph != '') echo '<p>' . $paragraph . '</p>';
                }
                ?>
                <footer>
                    <span class="author"><?= $article['name'] ?></span>
                    <span class="tags">
                        <?php foreach ($article['tags'] as $tag) { ?>
                            <a href="/">#<?= $tag ?></a>
                        <?php } ?>
                    </span>
                    <span class="date"><?= date('F j', $article['published']) ?></span>
                    <a class="comments" href="/article.php?id=<?= $article['id'] ?>#comments"><?= $article['comments'] ?></a>
                </footer>
            </article>

        <?php } ?>
    </section>
    <footer>
        <p>&copy; Fake News, 2022</p>
    </footer>
</body>

</html>
