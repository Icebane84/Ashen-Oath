// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDevilsBargainResolutionHandler.generated.h"

/**
 * UAshenDevilsBargainResolutionHandler
 * Handler executing Path A: Surrender (The Devil's Bargain) — triggering attack commitment reduction, enemy recoil/panic state AI, trust atrophy, and permanent spiritual stain.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDevilsBargainResolutionHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDevilsBargainResolutionHandler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Devil's Bargain")
	float TrustAtrophyAmount = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Devil's Bargain")
	bool ExecuteDevilsBargainSurrender();
};
