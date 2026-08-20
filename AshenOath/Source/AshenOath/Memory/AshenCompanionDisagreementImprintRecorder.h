// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenCompanionDisagreementImprintRecorder.generated.h"

/**
 * UAshenCompanionDisagreementImprintRecorder
 *
 * Captures relational friction between Garrett and Serafina during dialogue choices.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDisagreementImprintRecorder : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionDisagreementImprintRecorder();

	/** Records relational disagreement imprint between companions */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Memory")
	void RecordDisagreement(FName CompanionID, float Severity);
};
