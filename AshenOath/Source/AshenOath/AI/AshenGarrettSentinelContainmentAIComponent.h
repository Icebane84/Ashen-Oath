// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenGarrettSentinelContainmentAIComponent.generated.h"

/**
 * UAshenGarrettSentinelContainmentAIComponent
 * Garrett's AI decision tree: deploys Gloomwood suppressant throwing needles, drops smoke balms onto Kaelen, and escorts Serafina's casting.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettSentinelContainmentAIComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettSentinelContainmentAIComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	bool bIsEscortingSerafina = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void EvaluateGarrettContainmentTree(bool bIsKaelenUnchained, bool bIsSerafinaChanneling);
};
