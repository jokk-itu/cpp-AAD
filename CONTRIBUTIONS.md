<h1>Contributing to InstrumentDashboard</h1>
<hr>

<h3>Table of contents</h3>
<h4><a src="bug_reports_issue">Bug reports and issues</a></h4>
<ul>
<li><a src="#issue">How to write the good issue</a></li>
<li><a src="#issue_handling">Re-Open and Close issues</a></li>
</ul>
<h4><a src="#styleguides">Styleguides</a></h4>
<ul>
<li><a src="#commit">Git commit messages</a></li>
<li><a src="#branch">Branches</a></li>
<li><a src="#pull_request">Pull requests</a></li>
</ul>



<h2 id="bug_report_issue">Bug reports and issues</h2>
<hr>
<h3 id="issue">How to write the good issue</h3>
<hr>
<ul>
<li>Clear descriptive title</li>
<li>Describe the steps which to reproduce the issue</li>
<li>Describe the expected behaviour</li>
<li>Describe the actual behaviour</li>
<li>Link an image, if this can provide extra information</li>
</ul>

<h3 id="issue_handling">Re-Open and Close issues</h3>
<hr>
<ul>
<li>If you are Re-Opening an issue, explain why</li>
<li>If you are closing an issue, remember to link the appropiate Pull-Request (if there is reason to do so)</li>
</ul>

<h2 id="styleguide">Styleguides</h2>
<hr>
<h3 id="commit">Git commit messages</h3>
<hr>
<ul>
<li>Use the present tense "Add feature" "Fix issue" NOT "Fixed issue" "Added feature"</li>
<li>Limit the title to 72 characters or less. It should be short and concise.</li>
<li>There must be 2 line breaks after the title</li>
<li>Any line in the message, must be no longer than 50 characters. Then the message is readable.</li>
<li>After the two line breaks, a longer description can be made. To explain further what the commit contains. This can contain an unordered list, where each list element contains an edit</li>
</ul>

<h3 id="branch">Branches</h3>
<hr>
<ul>
<li>The master branch will contain production ready code. With possible bugs that has not been identified by the developers. (A program is never bug free</li>
<li>A development branch which contains new features. The code can be built and unit tested without errors. However bugs can be present, but must thoroughly checked for bugs, before merging with master.</li>
<li>Every new feature must be checked out from the development branch. And must use the naming convention: "topic/NAME_OF_FEATURE". This can be built, but contain unit test errors and runtime erros. There are no guarantees.</li>
</ul>
<h3 id="pull_request">Pull requests</h3>
<hr>
<ul>
<li>The title contains the name of the new main feature added</li>
<li>The description contains an unordered list of all features add. Written short and concise.</li>
<li>Issues, labels and projects must be added</li>
<li>Assign at least two developers to review the code. If in doubt write a comment or ask the developers for someone capable of reviewing the code.</li>
</ul>