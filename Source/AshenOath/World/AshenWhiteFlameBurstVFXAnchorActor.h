// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWhiteFlameBurstVFXAnchorActor.generated.h"

/**
 * AAshenWhiteFlameBurstVFXAnchorActor
 * World VFX anchor for explosive white flame bursts.
 */
UCLASS()
class ASHENOATH_API AAshenWhiteFlameBurstVFXAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenWhiteFlameBurstVFXAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Visuals")
	bool bIsBurstActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerBurstVFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerWhiteFlameBurstVFX(float Intensity = 1.0f);
};
