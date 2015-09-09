#include <QApplication>
#include <GJson.h>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GJson j = GJson::fromJson(
		"{"
		"joppa: \"Sraka!\","
		"\"pipiska\": true,"
		"list:[1,2,3,4,5.5,6.6,.1e-3]"
		"}"
	);
	j["test"] = 1.0;
	j["Жопа"] = "Срака!";
	j["Проверка"].resize( 5 );
	j["Проверка"][0] = true;
	j["pInfinity"]=std::numeric_limits<double>::infinity();
	j["nInfinity"]=-std::numeric_limits<double>::infinity();
	j["pNaN"]=std::numeric_limits<double>::quiet_NaN();
	j["nNaN"]=-std::numeric_limits<double>::quiet_NaN();
	j[QObject::trUtf8( "Проверка" )][1] = "Однажды в студёную зимнюю пору я из лесу вышел поссать на мороз.";

	qDebug( "j = \r\n%s", j.toJson().constData() );
#ifndef GQX_JSON_NO_MSGPACK
	QByteArray pMsgPack = j.msgpack();
	qDebug( "packed = %s", pMsgPack.toHex().constData() );

	GJson j1 = 	GJson::msgunpack( pMsgPack );
	qDebug( "j1 = \r\n%s", j1.toJson().constData() );
#endif

	MainWindow w;

	QMetaObject::invokeMethod( &w, "testJson", Qt::QueuedConnection, Q_ARG( GJson, j1 ) );

	w.show();

	return a.exec();
}
