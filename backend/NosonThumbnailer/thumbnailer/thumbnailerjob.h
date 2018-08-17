/*
 *      Copyright (C) 2018 Jean-Luc Barriere
 *
 *  This file is part of Noson-App
 *
 *  Noson-App is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Noson is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef THUMBNAILERJOB_H
#define THUMBNAILERJOB_H

#include <QObject>

namespace thumbnailer
{

  class Job;

  typedef enum {
    ReplySuccess        = 0,
    ReplyNetworkError   = 1,
    ReplyServerError    = 2,
    ReplyFatalError     = 3,
    ReplyInvalid        = 4,
  } ReplyStatus;

  class AbstractWorker : public QObject
  {
    friend class Job;

    Q_OBJECT
  public:
    AbstractWorker(QObject* parent = 0) : QObject(parent) { }

    virtual ~AbstractWorker() { }

    virtual void run() = 0;

    virtual ReplyStatus error() = 0;

    virtual int errorCode() = 0;

    virtual QString errorString() = 0;

    virtual const QByteArray& image() = 0;

    signals:
    void finished();

  };

  class Job final : public QObject
  {
    Q_OBJECT

  public:
    Q_DISABLE_COPY(Job)

    Job(AbstractWorker* worker, QObject* parent = 0);
    ~Job();

    void start();
    ReplyStatus error();
    int errorCode();
    QString errorString();
    const QByteArray& image();

    signals:
    void finished();

  private slots:
    void finishedWorker() { emit finished(); }

  private:
    AbstractWorker* m_worker; // the worker owned by this job
  };

}
#endif /* THUMBNAILERJOB_H */

