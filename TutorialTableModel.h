#include <QAbstractTableModel>
#include <vector>
#include "functionalities/Tutorial.h"

class TutorialTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Tutorial> tutorials;

public:
    TutorialTableModel(const std::vector<Tutorial>& tutorials, QObject* parent = nullptr)
        : QAbstractTableModel(parent), tutorials(tutorials) {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(tutorials.size());
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return 5; // Title, Presenter, Duration, Likes, Link
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole || !index.isValid())
            return QVariant();

        if (index.row() < 0 || index.row() >= static_cast<int>(tutorials.size()))
            return QVariant();

        const Tutorial& t = tutorials[index.row()];
        switch (index.column()) {
        case 0: return QString::fromStdString(t.getTitle());
        case 1: return QString::fromStdString(t.getPresenter());
        case 2: return QString("%1:%2").arg(t.getMinutes()).arg(t.getSeconds(), 2, 10, QChar('0'));
        case 3: return t.getLikes();
        case 4: return QString::fromStdString(t.getLink());
        default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
            return QVariant();

        switch (section) {
        case 0: return "Title";
        case 1: return "Presenter";
        case 2: return "Duration";
        case 3: return "Likes";
        case 4: return "Link";
        default: return QVariant();
        }
    }

    void setTutorials(const std::vector<Tutorial>& newTutorials) {
        beginResetModel();
        tutorials = newTutorials;
        endResetModel();
    }
};
