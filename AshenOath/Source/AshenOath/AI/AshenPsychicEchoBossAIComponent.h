// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPsychicEchoBossAIComponent.generated.h"

/**
 * UAshenPsychicEchoBossAIComponent
 * Boss AI behavior tree component modulating aggressive assault based on Kaelen's stance profile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychicEchoBossAIComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPsychicEchoBossAIComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	float AggressionMultiplier = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void UpdateBossStanceBehavior(uint8 StanceProfileEnum);
};
