// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalCompanionAISpacingAdapter.generated.h"

/**
 * UAshenJournalCompanionAISpacingAdapter
 * Dynamically increases companion patrol spacing from 300uu to 700uu with tensed combat posture under Guarded Friction.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalCompanionAISpacingAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalCompanionAISpacingAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	float CompanionFollowDistance = 300.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	bool bHandOnPommelStance = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void UpdateCompanionSpacingForFriction(bool bGuardedFriction);
};
