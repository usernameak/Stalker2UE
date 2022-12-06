#pragma once
#include "StalkerResourcesManager.generated.h"

UCLASS()
class UStalkerResourcesManager : public UObject
{
	GENERATED_BODY()
public:
	USlateBrushAsset*			GetBrush(FName NameMaterial, FName NameTexture);
	UFont*						GetFont(FName Name);
	void						Free(USlateBrushAsset* Brush);
	USlateBrushAsset*			Copy(USlateBrushAsset* Brush);
	void						CheckLeak();
	void						Reload();
	class AStalkerLight*		CreateLight();
	void						Desotry(class IRender_Light*Light);
	class AStalkerKinematics*	CreateKinematics(const char*Name);
	class AStalkerKinematics*	CreateKinematics(class UStalkerKinematicsData* KinematicsData);
	void						Destroy(class AStalkerKinematics* Mesh);

	class AStalkerKinematicsLegacy*	SpawnSkeletonMesh(class XRayKinematicsLegacy* Kinematics);
	void						Destroy(class AStalkerKinematicsLegacy*Mesh);
	UPROPERTY(Transient)
	TObjectPtr < class UWorld>	GameWorld;
private:

	UPROPERTY(Transient)
	TMap<FName, UFont*> Fonts;

	UPROPERTY(Transient)
	TMap<USlateBrushAsset*,int32> BrushesCounter;
	UPROPERTY(Transient)
	TMap<USlateBrushAsset*, UMaterialInstanceDynamic*> BrushesMaterials;
#if WITH_EDITORONLY_DATA
	TSet< USlateBrushAsset*>	 BrushesNeedReloading;
#endif
	TMap<FName, TMap<FName, USlateBrushAsset*>> Brushes;
	struct  BrushInfo
	{
		FName Matrrial;
		FName Texture;
	};
	TMap<USlateBrushAsset*, BrushInfo> BrushesInfo;
	
	UPROPERTY(Transient)
	TSet<AStalkerKinematicsLegacy*> MeshesLegacy;	
	
	UPROPERTY(Transient)
	TSet<AStalkerKinematics*> Meshes;

	UPROPERTY(Transient)
	TSet<class AStalkerLight*> Lights;
};