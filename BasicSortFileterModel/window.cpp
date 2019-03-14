#include "window.h"
#include <QHBoxLayout>
#include <QGridLayout>

Window::Window()
{
   proxyModel = new QSortFilterProxyModel;

   sourceView = new QTreeView;
   sourceView->setRootIsDecorated(false);
   sourceView->setAlternatingRowColors(true);

   proxyView = new QTreeView;
   proxyView->setRootIsDecorated(false);
   proxyView->setAlternatingRowColors(true);
   proxyView->setModel(proxyModel);
   proxyView->setSortingEnabled(true);

   sortCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive sorting"));
   filterCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive filter"));

  filterPatternLineEdit = new QLineEdit;
  filterPatternLabel = new QLabel(tr("&Filter pattern"));
  filterPatternLabel->setBuddy(filterPatternLineEdit);

  filterSyntaxComboBox = new QComboBox;
  filterSyntaxComboBox->addItem(tr("Regular expression"), QRegExp::RegExp);
  filterSyntaxComboBox->addItem(tr("WildCard"), QRegExp::Wildcard);
  filterSyntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
  filterSyntaxLabel = new QLabel(tr("Filter &syntax:"));
  filterSyntaxLabel->setBuddy(filterSyntaxComboBox);

  filterColumnComboBox = new QComboBox;
  filterColumnComboBox->addItem(tr("Subject"));
  filterColumnComboBox->addItem(tr("Sender"));
  filterColumnComboBox->addItem(tr("Date"));
  filterColumnLabel = new QLabel(tr("Filter &column:"));
  filterColumnLabel->setBuddy(filterColumnComboBox);

  connect(filterPatternLineEdit, &QLineEdit::textChanged,
          this, &Window::filterRegExpChanged);
  connect(filterSyntaxComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Window::filterRegExpChanged);
  connect(filterColumnComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &Window::filterColumnChanged);
  connect(filterCaseSensitivityCheckBox, &QAbstractButton::toggled, this, &Window::filterRegExpChanged);
  connect(sortCaseSensitivityCheckBox, &QAbstractButton::toggled,
          this, &Window::sortChanged);

  sourceGroupBox = new QGroupBox(tr("Original Model"));
  proxyGroupBox = new QGroupBox(tr("Sorted/Filtered Model"));

  QHBoxLayout *sourceLayout = new QHBoxLayout;

  sourceLayout->addWidget(sourceView);
  sourceGroupBox->setLayout(sourceLayout);

  QGridLayout *proxyLayout = new QGridLayout;
  proxyLayout->addWidget(proxyView, 0, 0, 1, 3);
  proxyLayout->addWidget(filterPatternLabel, 1, 0);
  proxyLayout->addWidget(filterPatternLineEdit, 1, 1, 1, 2);
  proxyLayout->addWidget(filterSyntaxLabel, 2, 0);
  proxyLayout->addWidget(filterSyntaxComboBox, 2, 1, 1, 2);
  proxyLayout->addWidget(filterColumnLabel, 3, 0);
  proxyLayout->addWidget(filterColumnComboBox, 3, 1, 1, 2);
  proxyLayout->addWidget(filterCaseSensitivityCheckBox, 4, 0, 1, 2);
  proxyLayout->addWidget(sortCaseSensitivityCheckBox, 4, 2);
  proxyGroupBox->setLayout(proxyLayout);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(sourceGroupBox);
  mainLayout->addWidget(proxyGroupBox);

  setLayout(mainLayout);

  setWindowTitle(tr("Basic Sort/FIlter Model"));
  resize(500, 450);

  proxyView->sortByColumn(1, Qt::AscendingOrder);
  filterColumnComboBox->setCurrentIndex(1);

  filterPatternLineEdit->setText("Andy|Grace");
  filterCaseSensitivityCheckBox->setChecked(true);
  sortCaseSensitivityCheckBox->setChecked(true);
}

Window::~Window()
{

}

void Window::setSourceModel(QAbstractItemModel *model)
{
   proxyModel->setSourceModel(model);
   sourceView->setModel(model);
}

void Window::filterRegExpChanged()
{
    QRegExp::PatternSyntax syntax =
            QRegExp::PatternSyntax(filterSyntaxComboBox->itemData(filterSyntaxComboBox->currentIndex()).toInt());

    Qt::CaseSensitivity caseSensitivity = filterCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive:
                                                                                       Qt::CaseInsensitive;

    QRegExp regExp(filterPatternLineEdit->text(), caseSensitivity, syntax);

    proxyModel->setFilterRegExp(regExp);
}

void Window::filterColumnChanged()
{
    proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
}

void Window::sortChanged()
{
    proxyModel->setSortCaseSensitivity(
                sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                         : Qt::CaseInsensitive);
}











