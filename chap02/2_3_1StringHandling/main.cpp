#include <QtCore>

QTextStream cout(stdout, QIODevice::WriteOnly);


int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QString s1("Paris");
    QString s2("London");

    //string concatenation
    QString s = s1 + " " + s2 + ";";

    QString s3("Hello");
    QString s4("Qt");

    QList<QString> list;

    list << s3 << s4;

    QListIterator<QString> iter(list);

    while(iter.hasNext())
    {
        cout << iter.next();
        if(iter.hasNext())
            cout << " ";
    }

    cout << "!" << endl;

    QString joined = list.join(" ") + "!";

    cout << joined << endl;

    QList<QStringList> data;

    QFile file("sample.csv");



    cout << "Oeffne Datei " + file.fileName();

    if(file.open(QIODevice::ReadOnly))
    {
        cout << "...done." << endl;

        QTextStream stream(&file);

        int lineNumber = 0;
        forever
        {

            cout << "Reading line " << ++lineNumber << " from file." << endl;

            QString line = stream.readLine();
            //test for NULL-String
            if(line.isNull())
            {
                cout << "Read  NULL-String - leaving reading loop..." << endl;
                break;
            }

            //test for empty string
            if(line.isEmpty())
            {
                cout << "Read empty string...continuing with next line" << endl;
                continue;
            }

            QStringList row;
            cout << "Read non empty line - parsing text" << endl;
            cout << "Splitting line " << line << " into tokens..." << endl;
            //for each loop to iterate over containers
            foreach(const QString &cell, line.split(","))
            {
                cout << cell << endl;
                row.append(cell.trimmed());
            }

            data.append(row);
        }
    }

}
