#include "AssetViewer_Viewport.h"
#include "AssetViewer_Viewport_Client.h"
#include "AdvancedPreviewScene.h"
#include "Components/StaticMeshComponent.h"

SAssetViewer_Viewport::SAssetViewer_Viewport()
{
	Scene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));
}

void SAssetViewer_Viewport::Construct(const FArguments& InArgs)
{
	SEditorViewport::Construct(InArgs);

	UStaticMesh* floorMeshAsset = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Engine/MapTemplates/SM_Template_Map_Floor.SM_Template_Map_Floor'"));
	FloorMesh = NewObject<UStaticMeshComponent>(GetTransientPackage(), NAME_None ,RF_Transient);
	FloorMesh->SetStaticMesh(floorMeshAsset);

	UStaticMesh* assetMeshAsset = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Engine/EditorMeshes/Camera/SM_RailRig_Mount.SM_RailRig_Mount'"));
	AssetMesh = NewObject<UStaticMeshComponent>(GetTransientPackage(), NAME_None ,RF_Transient);
	AssetMesh->SetStaticMesh(assetMeshAsset);

	FTransform tranform;
	Scene->AddComponent(FloorMesh, tranform);

	tranform.SetLocation(FVector(0, 0, 100));
	tranform.SetScale3D(FVector(5));
	Scene->AddComponent(AssetMesh, tranform);
}

TSharedRef<FAdvancedPreviewScene> SAssetViewer_Viewport::GetScene()
{
	return Scene.ToSharedRef();
}

TSharedRef<FEditorViewportClient> SAssetViewer_Viewport::MakeEditorViewportClient()
{
	ViewportClient =  MakeShareable(new FAssetViewer_Viewport_Client(Scene.Get(), SharedThis(this)));

	return ViewportClient.ToSharedRef();
}

void SAssetViewer_Viewport::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(AssetMesh);
	Collector.AddReferencedObject(FloorMesh);
}

