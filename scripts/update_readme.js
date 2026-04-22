const fs = require("fs");
const fetch = require("node-fetch");

const folders = fs.readdirSync("./")
  .filter(f => /^\d+-/.test(f));

// Extract slug
const getSlug = (name) => name.split("-").slice(1).join("-");

// Extract problem number
const getNumber = (name) => parseInt(name.split("-")[0]);

// Difficulty badge
const diffBadge = (d) => {
  if (d === "Easy") return "🟢 Easy";
  if (d === "Medium") return "🟡 Medium";
  return "🔴 Hard";
};

// Topic badges
const topicBadge = (topics) =>
  topics.map(t => `\`${t}\``).join(" ");

async function fetchProblem(slug) {
  try {
    const res = await fetch("https://leetcode.com/graphql", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        query: `
          query getQuestion($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
              title
              difficulty
              topicTags {
                name
              }
            }
          }
        `,
        variables: { titleSlug: slug },
      }),
    });

    const json = await res.json();
    const q = json.data?.question;

    if (!q) return null;

    return {
      title: q.title,
      difficulty: q.difficulty,
      topics: q.topicTags.map(t => t.name),
    };
  } catch {
    return null;
  }
}

async function main() {
  const sorted = folders.sort((a, b) => getNumber(a) - getNumber(b));

  // 🚀 Parallel fetch
  const results = await Promise.all(
    sorted.map(async folder => {
      const slug = getSlug(folder);
      const data = await fetchProblem(slug);
      return { folder, slug, data };
    })
  );

  let table = `| # | Problem | Difficulty | Topics |\n`;
  table += `|---|--------|------------|--------|\n`;

  let count = 0;

  results.forEach((item, idx) => {
    if (!item.data) return;

    count++;

    table += `| ${idx + 1} | [${item.data.title}](https://leetcode.com/problems/${item.slug}) | ${diffBadge(item.data.difficulty)} | ${topicBadge(item.data.topics)} |\n`;
  });

  let readme = fs.readFileSync("README.md", "utf-8");

  // Update table
  readme = readme.replace(
    /<!-- START_TABLE -->[\s\S]*<!-- END_TABLE -->/,
    `<!-- START_TABLE -->\n${table}\n<!-- END_TABLE -->`
  );

  // Update count
  readme = readme.replace(
    /<!-- TOTAL_COUNT -->/,
    count
  );

  fs.writeFileSync("README.md", readme);

  console.log("🔥 README upgraded successfully");
}

main();
