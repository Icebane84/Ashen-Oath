// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGarrettShadowSnareTrapActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShadowSnareTriggeredSignature, AActor*, TrappedEnemy, float, RootDurationSeconds);

/**
 * AAshenGarrettShadowSnareTrapActor
 *
 * Interactive World Actor deploying shadow snare traps in level space (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API AAshenGarrettShadowSnareTrapActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenGarrettShadowSnareTrapActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShadowSnare")
	void TriggerShadowSnare(AActor* TargetEnemy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShadowSnare|Events")
	FOnShadowSnareTriggeredSignature OnShadowSnareTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowSnare")
	bool bIsArmed = true;
};
