// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenLuminousAegisNetActor.generated.h"

/**
 * AAshenLuminousAegisNetActor
 * 3D world actor rendering a volumetric lattice of vibrating golden threads around Kaelen's collision capsule.
 */
UCLASS()
class ASHENOATH_API AAshenLuminousAegisNetActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLuminousAegisNetActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float LatticeGlowIntensity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	void SetLatticeTensionVisual(float TensionScalar);
};
