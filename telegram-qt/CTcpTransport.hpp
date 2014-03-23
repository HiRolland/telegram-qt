#ifndef CTCPTRANSPORT_HPP
/*
    Copyright (C) 2014 Alexandr Akulich <akulichalexander@gmail.com>

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#define CTCPTRANSPORT_HPP


#include "CTelegramTransport.hpp"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

class CTcpTransport : public CTelegramTransport
{
    Q_OBJECT
public:
    explicit CTcpTransport(QObject *parent = 0);

    void connectToDc(const SDataCenter &dc);

    QByteArray getPackage() { return m_receivedPackage; }

    QByteArray lastPackage() const { return m_lastPackage; }

public slots:
    void sendPackage(const QByteArray &payload);

private slots:
    void whenConnected();
    void whenReadyRead();

private:
    quint32 m_packetNumber;
    quint32 m_expectedLength;

    QByteArray m_receivedPackage;
    QByteArray m_lastPackage;

    QTcpSocket *m_socket;

};

#endif // CTCPTRANSPORT_HPP