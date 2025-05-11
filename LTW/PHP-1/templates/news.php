<?php

function output_article($article, $comments = null) { ?>
    <article>
        <header>
            <h1><a href="/article.php?id=<?= $article['id'] ?>"><?= $article['title'] ?></a></h1>
        </header>
        <img src="https://picsum.photos/600/300?<?= $article['id'] ?>" alt="" />
        <p>
            <?= $article['introduction'] ?>
        </p>
        <?php foreach (explode("\n", $article['fulltext']) as $paragraph)
            if ($paragraph != '') echo '<p>' . $paragraph . '</p>';
        ?>
        <?php if ($comments !== null) { ?>
            <section id="comments">
                <h1><?= count($comments) ?> Comments</h1>
                <?php foreach ($comments as $comment) { ?>
                    <article class="comment">
                        <span class="user"><?= $comment['username'] ?></span>
                        <span class="date"><?= date('F j', $comment['published']) ?></span>
                        <p><?= $comment['text'] ?></p>
                    </article>
                <?php } ?>
                <form>
                    <h2>Add your voice...</h2>
                    <label>Username
                        <input type="text" name="username" />
                    </label>
                    <label>E-mail
                        <input type="email" name="email" />
                    </label>
                    <label>Comment
                        <textarea name="comment"></textarea>
                    </label>
                    <button formaction="#" formmethod="post">Reply</button>
                </form>
            </section>
        <?php } ?>
        <footer>
            <span class="author"><?= $article['name'] ?></span>
            <span class="tags">
                <?php foreach (explode(',', $article['tags']) as $tag) { ?>
                    <a href="/">#<?= $tag ?></a>
                <?php } ?>
            </span>
            <span class="date"><?= date('F j', $article['published']) ?></span>
            <a class="comments" href="/article.php?id=<?= $article['id'] ?>#comments"><?= $article['comments'] ?></a>
            <a class="edit-button" href="/edit_article.php?id=<?= $article['id'] ?>"> &#9998; </a>
        </footer>
    </article>
<?php }

function output_edit_article($article) { ?>
    <form action="action_edit_article.php" method="post">
        <input type="hidden" name="id" value="<?= htmlspecialchars($article['id']) ?>">
        <label>Title
            <input type="text" name="title" value="<?= htmlspecialchars($article['title']) ?>">
        </label>
        <label>Introduction
            <textarea name="introduction" rows="10"><?= htmlspecialchars($article['introduction']) ?></textarea>
        </label>
        <label>Full Text
            <textarea name="fulltext" rows="16"><?= htmlspecialchars($article['fulltext']) ?></textarea>
        </label>
        <button type="submit">Submit</button>
    </form>
<?php }
