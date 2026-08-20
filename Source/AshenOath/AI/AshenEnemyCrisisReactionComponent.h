// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemyCrisisReactionComponent.generated.h"

/**
 * UAshenEnemyCrisisReactionComponent
 * AI component driving enemy recoil/panic states (Path A) or momentum shatter / overcommitment confusion phases (Path B).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemyCrisisReactionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemyCrisisReactionComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bInRecoilPanicState = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void TriggerPredatoryRecoilPanic();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void TriggerMomentumShatterOvercommitment();
};
