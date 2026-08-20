// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenRelationalContextBarkDispatcher.generated.h"

class USoundBase;
class UAudioComponent;

/**
 * UAshenRelationalContextBarkDispatcher
 * 
 * Dispatches dynamic voice barks based on companion's inferred intent:
 * - "Damn it. There goes our Mr. Hero again."
 * - "God damn it Kaelen, I said wait!"
 * - "No. Not this time. Pull back!"
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalContextBarkDispatcher : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalContextBarkDispatcher();

	/** Dispatches contextual audio bark */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Barks")
	void DispatchBark(const FCompanionIntentEvaluationResult& Evaluation, USoundBase* BarkSound);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Barks")
	const FString& GetLastBarkDialogue() const { return LastDispatchedDialogue; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* BarkAudioComponent;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Audio|Barks")
	FString LastDispatchedDialogue;
};
