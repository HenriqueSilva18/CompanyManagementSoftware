<h1>Enterprise Management Software</h1>


<h2>Description</h2>
This project is an enterprise management system developed in C, designed to manage company information, activity sectors, and provide analytical reports. It enables 'administrators' to add, edit, remove, and search for companies, manage business sectors, and generate reports based on reviews and ratings. It also enables 'users' to search, rate and comment whichever company they want to.
<br />


<h2>Technologies Used</h2>
    <ul>
        <li>Programming Language: C</li>
        <li>Binary File Manipulation for Data Storage</li>
        <li>Dynamic Data Structures</li>
    </ul>

<h2>Features</h2>
    <ul>
        <li><strong>Company Management</strong>: Add, edit, remove, and search for companies in the catalog.</li>
        <li><strong>Ratings and Reviews</strong>: Allow users to rate and comment on companies.</li>
        <li><strong>Activity Sector Management</strong>: Manage the inclusion, editing, and removal of various business sectors.</li>
        <li><strong>Analytical Reports</strong>: Generate reports based on average ratings and the number of comments.</li>
        <li><strong>Data Persistence</strong>: Save and load data to/from binary files, maintaining data across sessions.</li>
    </ul>

<h2>Project Structure</h2>
    <ul>
        <li><code>main.c</code>: The entry point of the program, handling user interactions and overall flow.</li>
        <li><code>Gestao_Empresas.h/c</code>: Modules for managing companies.</li>
        <li><code>Gestao_Ramos_Atividades.h/c</code>: Modules for managing business sectors.</li>
        <li><code>relatorios.h/c</code>: Modules for generating reports.</li>
        <li><code>ficheiros.h/c</code>: Modules for file manipulation (reading and writing).</li>
        <li><code>utilizador.h/c</code>: Modules for users to search, rate and comment companies.</li>
    </ul>
<!--
 ```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```
--!>
