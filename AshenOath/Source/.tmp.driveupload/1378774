// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "SentinelGraphSynthesizer.h"
#include "AshenBatchAuthoringSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenFeatureAssetType : uint8
{
	DialogueDataAsset UMETA(DisplayName = "Dialogue Data Asset"),
	GameplayAbilityBlueprint UMETA(DisplayName = "Gameplay Ability Blueprint")
};

USTRUCT(BlueprintType)
struct FAshenTriDomainBatchPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Batch Definitions")
	FName BatchIdentifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Domain: Mechanics")
	FString RequiredGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Domain: AudioVisual")
	FName LinkedMetaSoundParameter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Domain: Narrative")
	float SoulStateVectorThreshold = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Batch Definitions")
	EAshenFeatureAssetType AssetType = EAshenFeatureAssetType::DialogueDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Batch Definitions")
	FImprintTelemetrySpec TelemetrySpec;
};

/**
 * UAshenBatchAuthoringSubsystem
 * Editor-only subsystem enforcing Tri-Domain Batch Compilation & Cross-Domain Convergence.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBatchAuthoringSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Orchestrates creation of a Tri-Domain batch */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|BatchAuthoring")
	bool OrchestrateNewFeatureBatch(const FAshenTriDomainBatchPayload& Payload);

	/** Validates that existing batch links are synchronized */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Validation")
	bool ValidateDomainLinks(FName BatchIdentifier) const;

private:
	bool InjectGameplayTagToConfig(const FString& TagString) const;
	bool RegisterAudioVisualBlackboardLink(FName ParameterName) const;
	void LogBatchOperation(const FString& Message, bool bIsError = false) const;
};
