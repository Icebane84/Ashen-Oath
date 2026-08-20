// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenHeartstoneCampfireActor.generated.h"

class UAshenSanctuaryHeartstoneCrucibleComponent;
class UAshenSLMCompilerSubsystem;

/**
 * AAshenHeartstoneCampfireActor
 *
 * Interactive Sanctuary Campfire Rest Shrine Actor.
 * Aggregates mechanical imprints, triggers the SLM Identity Compiler bridge,
 * and updates Kaelen's psychological state upon successful firewall verification.
 */
UCLASS()
class ASHENOATH_API AAshenHeartstoneCampfireActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenHeartstoneCampfireActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAshenSanctuaryHeartstoneCrucibleComponent* CrucibleComponent;

public:
	/** Triggers rest sequence and identity compilation request */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Campfire")
	void ExecuteCampfireRest();

	/** Callback when compiler subsystem finishes parsing payload */
	UFUNCTION()
	void OnCompilationCompleted(bool bSuccess, const FSoulStateVector& UpdatedVector);
};
