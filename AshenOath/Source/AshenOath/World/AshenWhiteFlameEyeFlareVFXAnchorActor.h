// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWhiteFlameEyeFlareVFXAnchorActor.generated.h"

/**
 * AAshenWhiteFlameEyeFlareVFXAnchorActor
 * World VFX anchor driving white flame eye flares during unchained vessel abilities.
 */
UCLASS()
class ASHENOATH_API AAshenWhiteFlameEyeFlareVFXAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenWhiteFlameEyeFlareVFXAnchorActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerEyeFlareVFX();
};
