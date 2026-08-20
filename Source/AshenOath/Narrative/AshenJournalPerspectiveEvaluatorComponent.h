// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenJournalPerspectiveEvaluatorComponent.generated.h"

/**
 * UAshenJournalPerspectiveEvaluatorComponent
 * Evaluates whether a combat resolution was executed in Solitary Martyrdom or Tripartite Synarchy based on trust, corruption, and sync finisher usage.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalPerspectiveEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalPerspectiveEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	EJournalPerspectiveType EvaluateResolutionPerspective(bool bUsedSyncFinisher, float MutualTrust, float Corruption);
};
