// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPhysicalTraumaLightBridgeActor.generated.h"

/**
 * AAshenPhysicalTraumaLightBridgeActor
 * 3D world actor rendering solid glowing filament bridge geometry with interactive navmesh walking surfaces over void chasms.
 */
UCLASS()
class ASHENOATH_API AAshenPhysicalTraumaLightBridgeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenPhysicalTraumaLightBridgeActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	bool bIsNavmeshActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	void SolidifyBridgeMesh();
};
