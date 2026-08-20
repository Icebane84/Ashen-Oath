// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalPageTurnPostProcessAdapter.generated.h"

/**
 * UAshenJournalPageTurnPostProcessAdapter
 * 
 * Drives subtle Depth-Of-Field and vignette shifts when inspecting the living journal.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalPageTurnPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalPageTurnPostProcessAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Toggles journal inspection focus */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|PostProcess")
	void SetJournalFocus(bool bInFocus);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|PostProcess")
	float GetFocusScalar() const { return CurrentFocus; }

private:
	float CurrentFocus = 0.0f;
	float TargetFocus = 0.0f;
};
