#include "StaticMesh_DetailPanel.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Actors/CMeshActor.h"

TSharedRef<IDetailCustomization> FStaticMesh_DetailPanel::MakeInstance()
{
	return MakeShareable(new FStaticMesh_DetailPanel());
}

void FStaticMesh_DetailPanel::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& catetory = DetailBuilder.EditCategory("AwesomeCategory");

	catetory.AddCustomRow(FText::FromString("Shuffle Material"))
	.NameContent()
	[
		SNew(STextBlock)
		.Text(FText::FromString("Material Instance"))
	]
	.ValueContent()
	.HAlign(HAlign_Left)
	.MaxDesiredWidth(250)
	[
		SNew(SButton)
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Fill)
		.OnClicked(this, &FStaticMesh_DetailPanel::OnClicked_ShuffleMatrial)
		.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString("Shuffle"))
		]
	];

	catetory.AddCustomRow(FText::FromString("Save Mesh"))
	.NameContent()
	[
		SNew(STextBlock)
		.Text(FText::FromString("Save Mesh"))
	]
	.ValueContent()
	.HAlign(HAlign_Left)
	.MaxDesiredWidth(250)
	[
		SNew(SButton)
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Fill)
		.OnClicked(this, &FStaticMesh_DetailPanel::OnClicked_SaveMesh)
		.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString("Save To Binary File"))
		]
	];

	DetailBuilder.GetObjectsBeingCustomized(Objects);
}

FReply FStaticMesh_DetailPanel::OnClicked_ShuffleMatrial()
{
	ACMeshActor* actor = Cast<ACMeshActor>(Objects[0]);
	if (actor == nullptr) return FReply::Unhandled();

	actor->ShuffleMaterial();

	return FReply::Handled();
}

FReply FStaticMesh_DetailPanel::OnClicked_SaveMesh()
{
	//Todo. File Dialog
	return FReply::Handled();
}