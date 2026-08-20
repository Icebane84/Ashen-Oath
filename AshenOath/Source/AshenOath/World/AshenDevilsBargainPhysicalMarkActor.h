// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDevilsBargainPhysicalMarkActor.generated.h"

/**
 * AAshenDevilsBargainPhysicalMarkActor
 * Physical world visual locus actor rendering the Shadow's Mark rune pulse in-world on Kaelen's forearm during crisis temporal dilation (zero HUD).
 */
UCLASS()
class ASHENOATH_API AAshenDevilsBargainPhysicalMarkActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenDevilsBargainPhysicalMarkActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Mark")
	float MarkRunePulseIntensity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Mark")
	bool TriggerInWorldMarkRunePulse();
};
