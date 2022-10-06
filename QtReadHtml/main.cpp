#include <QCoreApplication>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QUrl url("http://google.com");
  QNetworkAccessManager manager;
  QNetworkRequest request(url);
  QNetworkReply *reply(manager.get(request));
  QEventLoop loop;
  QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
  loop.exec();
  qDebug(reply->readAll());

  return a.exec();
}
