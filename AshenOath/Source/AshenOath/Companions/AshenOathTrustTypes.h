// AshenOathTrustTypes.h
// TAM-001 v2 — core types for the asymmetric pairwise Trust/Memory Model.
// Spec source: PHOENIX SYNARCHE / GDD-PIPELINE-002, TAM-001-V2-RESOLUTIONS (2026-07-29)

#pragma once

#include "CoreMinimal.h"
#include "AshenOathTrustTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenOathCompanion : uint8
{
	Kaelen,
	Garrett,
	Serafina,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EAshenOathTrustBand : uint8
{
	Guarded,
	Cautious,
	Cooperative,
	Synchronized
};

/** Directional key: HOW MUCH Truster trusts Trustee. Non-commutative by design. */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenOathTrustPairKey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	EAshenOathCompanion Truster = EAshenOathCompanion::Kaelen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	EAshenOathCompanion Trustee = EAshenOathCompanion::Garrett;

	FAshenOathTrustPairKey() = default;
	FAshenOathTrustPairKey(EAshenOathCompanion InTruster, EAshenOathCompanion InTrustee)
		: Truster(InTruster), Trustee(InTrustee) {}

	bool operator==(const FAshenOathTrustPairKey& Other) const
	{
		return Truster == Other.Truster && Trustee == Other.Trustee;
	}
};

FORCEINLINE uint32 GetTypeHash(const FAshenOathTrustPairKey& Key)
{
	return HashCombine(GetTypeHash(static_cast<uint8>(Key.Truster)), GetTypeHash(static_cast<uint8>(Key.Trustee)));
}

/** One threshold row in the Behavior Adaptation lookup table. Entry/Exit differ for hysteresis. */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenOathTrustBandThreshold
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	EAshenOathTrustBand Band = EAshenOathTrustBand::Guarded;

	/** Trust must be >= this to ENTER the band from below. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	float EnterTrust = 0.f;

	/** Trust must fall below this to EXIT the band. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	float ExitTrust = 0.f;

	/** Minimum rolling Momentum required to enter. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trust")
	float MinMomentumToEnter = -1.f;
};

/** Rolling per-pair state. */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenOathTrustPairState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Trust")
	float Trust = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Trust")
	double LastEventTimestamp = -1.0;

	UPROPERTY(BlueprintReadOnly, Category = "Trust")
	EAshenOathTrustBand CurrentBand = EAshenOathTrustBand::Cautious;

	/** Signed outcome history for the last K events, used to compute Momentum. */
	UPROPERTY()
	TArray<float> RecentDeltaSigns;
};

/** Tracks a single in-progress post-spike stabilization window for RecoveryQuality scoring. */
USTRUCT()
struct FAshenOathRecoveryWindowState
{
	GENERATED_BODY()

	bool bActive = false;
	double WindowStartTime = 0.0;
	double WindowDuration = 10.0; // seconds

	/** Which companions performed a recognized cooperative recovery action during the window. */
	TSet<EAshenOathCompanion> ParticipatingCompanions;

	/** Timestamps of each recovery action. */
	TArray<double> ActionTimestamps;

	/** Set true if the party took further significant damage during the window. */
	bool bAdditionalDamageTaken = false;
};
