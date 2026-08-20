// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenJournalHandwritingPhenotypeIntegrator.generated.h"

/**
 * UAshenJournalHandwritingPhenotypeIntegrator
 * Connects diegetic journal handwriting morphs to FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalHandwritingPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalHandwritingPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Journal")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Journal")
	float GetHandwritingWobbleScalar() const { return HandwritingWobbleScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Journal")
	float HandwritingWobbleScalar = 0.0f;
};
