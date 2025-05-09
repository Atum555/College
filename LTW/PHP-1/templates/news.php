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
        </footer>
    </article>
<?php }
