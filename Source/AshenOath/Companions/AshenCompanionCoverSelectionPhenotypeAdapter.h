// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionCoverSelectionPhenotypeAdapter.generated.h"

/**
 * UAshenCompanionCoverSelectionPhenotypeAdapter
 * Binds Garrett cover selection aggressiveness to ETacticalProfile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionCoverSelectionPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionCoverSelectionPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetCoverAggressiveness() const { return CoverAggressiveness; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float CoverAggressiveness = 0.5f;
};
