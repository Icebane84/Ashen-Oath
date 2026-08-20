// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_StruggleComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenStrugglePhase : uint8
{
	None            UMETA(DisplayName = "None"),
	DiscordantHum   UMETA(DisplayName = "Phase 1: Discordant Hum (Resisting Whispers)"),
	MartyrPivot     UMETA(DisplayName = "Phase 2: Martyr's Pivot (Protective Intercept)"),
	ReclamationCrash UMETA(DisplayName = "Phase 3: Reclamation Crash (Resetting Bone)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStruggleStateChangedSignature, EAshenStrugglePhase, CurrentPhase, float, ProgressAlpha);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStruggleResolvedSignature, bool, bPlayerWon);

/**
 * UAshenOath_StruggleComponent
 *
 * Manages Kaelen's psychological battle against the Shadow Self,
 * handling controller friction, dynamic QTE struggle phases, and protective intercepts.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_StruggleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_StruggleComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Struggle")
	EAshenStrugglePhase CurrentPhase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Struggle")
	float StruggleProgress; // Range: 0.0f to 1.0f

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Struggle")
	float StruggleDuration = 6.0f; // Seconds before auto-failure

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Struggle")
	float TimerTracker;

	/** Initiates a struggle phase (Discordant Hum, Martyr's Pivot, or Reclamation Crash). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Struggle")
	void StartStrugglePhase(EAshenStrugglePhase NewPhase);

	/** Processes player button mash / stick struggle input, advancing progress towards 1.0. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Struggle")
	void SubmitStruggleInput(float ResistanceAmount = 0.15f);

	/** Resolves active struggle phase. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Struggle")
	void ResolveStruggle(bool bPlayerWon);

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Struggle|Events")
	FOnStruggleStateChangedSignature OnStruggleStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Struggle|Events")
	FOnStruggleResolvedSignature OnStruggleResolved;
};
